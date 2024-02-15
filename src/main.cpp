#include "../include/window/window.hpp"
#include "../include/nlohmann/json.hpp"
#include <fstream>


nlohmann::json getJson(const std::filesystem::path& filePath) {
    std::ifstream jsonFile(filePath);
    nlohmann::json jsonData = nlohmann::json::parse(jsonFile);
    return jsonData;
}


void init() {

    nlohmann::json settings = getJson(re::SETTINGS_FILE);
    std::filesystem::path mangaFolder(settings["main_folder"]);

    for (const auto& mangaPath : std::filesystem::directory_iterator(mangaFolder)) {
        const std::filesystem::path& path = mangaPath.path();
        re::globals::mangaByName.insert(
            {
                path.stem().string(),
                std::make_shared<re::Manga>(path)
            }
        );
    }

    nlohmann::json mangas = getJson(re::MANGAS_FILE);
    for (const auto& mangaInfo : mangas) {
        const std::string& name = mangaInfo["name"];
        try {
            std::shared_ptr<re::Manga>& m = re::globals::mangaByName.at(name);
            m->deserialize(mangaInfo);            
        } catch (std::out_of_range& e) {
            std::cout << "Manga " << name << " not fond\n";
        }
    }

}


/* portions derived from IJG code */

#define readbyte(a,b) do if(((a)=getc((b))) == EOF) return 0; while (0)
#define readword(a,b) do { int cc_=0,dd_=0; \
                          if((cc_=getc((b))) == EOF \
        		  || (dd_=getc((b))) == EOF) return 0; \
                          (a) = (cc_<<8) + (dd_); \
                          } while(0)


int scanhead (FILE * infile, int * image_width, int * image_height) {
  int marker=0;
  int dummy=0;
  if ( getc(infile) != 0xFF || getc(infile) != 0xD8 )
    return 0;

  for (;
      ;) {


    int discarded_bytes=0;
    readbyte(marker,infile);
    while (marker != 0xFF) {
      discarded_bytes++;
      readbyte(marker,infile);
    }
    do readbyte(marker,infile); while (marker == 0xFF);

    if (discarded_bytes != 0) return 0;
   
    switch (marker) {
    case 0xC0:
    case 0xC1:
    case 0xC2:
    case 0xC3:
    case 0xC5:
    case 0xC6:
    case 0xC7:
    case 0xC9:
    case 0xCA:
    case 0xCB:
    case 0xCD:
    case 0xCE:
    case 0xCF: {
      readword(dummy,infile);	/* usual parameter length count */
      readbyte(dummy,infile);
      readword((*image_height),infile);
      readword((*image_width),infile);
      readbyte(dummy,infile);

      return 1;
      break;
      }
    case 0xDA:
    case 0xD9:
      return 0;
    default: {
	int length;
	
	readword(length,infile);

	if (length < 2)
	  return 0;
	length -= 2;
	while (length > 0) {
	  readbyte(dummy, infile);
	  length--;
	}
      }
      break;
    }
  }
}

void close() {
    nlohmann::json jsonData;
    
    for (auto& [name, manga] : re::globals::mangaByName) {
        manga->serialize(jsonData);
    }
    
    std::ofstream jsonFile(re::MANGAS_FILE);
    jsonFile << std::setw(4) << jsonData;

    re::TexturePool::rmvAll();
    re::FontPool::rmvAll();
}



int main() {
    init();
    re::Window w;
    w.run();
    close();
    return EXIT_SUCCESS;
}
