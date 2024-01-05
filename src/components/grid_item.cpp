#include "../../include/components/grid_item.hpp"


re::GridItem::GridItem(
    re::Manga* manga
) : re::Component("GridItem-" + manga->name),
    manga(manga) {
    this->image = new re::Sprite(manga->coverImagePath);    
    this->transform.setSize(this->image->transform.getSize());
    this->rect = new re::Rect(
        {{}, re::constants::GRID_ITEM_RECT_SIZE}, 
        re::constants::GRID_ITEM_RECT_COLOR
    );
    this->initTxt();
}


re::GridItem::~GridItem() {
    delete this->image;
    delete this->rect;
}


void re::GridItem::initTxt() {
    const std::string& mangaName = manga->name;
    const re::Style::TextStyle& txtStyle = re::Style::coverTxtStyle;

    const sf::Vector2f txtSize = re::Font::getStrSize(mangaName, txtStyle.size, txtStyle.font);

    const int lines = std::round((0.5 + (txtSize.x / this->rect->transform.width())));    
    const std::size_t charPerLine = mangaName.size() / lines;
    
    std::vector<std::string> words;
    re::split(mangaName, ' ', words);
    std::string currentStr;
    for (const std::string& s : words) {
        if (currentStr.size() + s.size() > charPerLine) {
            this->texts.insert(this->texts.begin(), new re::Text(currentStr, txtStyle));
            currentStr = "";
        } 
        currentStr += s + ' ';
    }

    if (!currentStr.empty())
        this->texts.insert(this->texts.begin(), new re::Text(currentStr, txtStyle));

    this->rect->transform.setHeight(txtSize.y * this->texts.size() + 30);

}


void re::GridItem::setPos(const sf::Vector2f& pos) {
    this->image->transform.setPos(pos);
    this->transform.setPos(pos);
    this->rect->transform.setBottom(this->transform.bottom());
    this->rect->transform.setLeft(this->transform.left());
    re::Text* lastLine = nullptr;
    for (std::size_t i = 0; i < this->texts.size(); i++) {
        re::Text* t = this->texts.at(i);
        if (lastLine == nullptr)
            t->transform.setBottom(this->rect->transform.bottom() - 20);
        else
            t->transform.setBottom(lastLine->transform.top() - 5);
        lastLine = t;
        t->transform.setCenterX(this->rect->transform.centerX());
    }
}


void re::GridItem::draw(sf::RenderWindow& window) {
    this->image->draw(window);
    this->rect->draw(window);
    for (re::Text* t : this->texts)
        t->draw(window);
}


void re::GridItem::moveY(const float& y) {
    this->setPos({this->transform.left(), this->transform.top() + y});
}


const std::string& re::GridItem::getMangaName() const {
    return this->manga->name;
}