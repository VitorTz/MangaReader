#ifndef MANGA_READER_STATUS_HPP
#define MANGA_READER_STATUS_HPP



namespace re {

    enum class StateId {
        Active,
        Inactive
    };

    template<typename T> class State {

        private:
            const T x, y;
            
        public:
            State(const T& x, const T& y);
            const T& get(const re::StateId& state) const;

    };

    template<typename T>
    re::State<T>::State(const T& x, const T& y) : x(x), y(y) { }


    template<typename T>
    const T& re::State<T>::get(const re::StateId& state) const {
        switch (state) {
            case re::StateId::Inactive :
                return this->x;
                break;
            case re::StateId::Active:
                return this->y;
                break;
            default:
                break;
        }
        return this->x;
    }
    
} // namespace re


#endif