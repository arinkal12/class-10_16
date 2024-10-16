#include "Set.h"
#include <cmath>
#include <vector>

Set::Set(size_t mp) : _bitField(mp){
    _maxPower = mp;
}

Set:: Set(const Set& set): _bitField(set._maxPower){
    _maxPower = set._maxPower;
    _bitField = set._bitField;
};
Set::Set(const BitField& bf) : _bitField(bf){
    _bitField = bf;
    _maxPower = bf.GetLength();
};
Set::operator BitField(){
    return _bitField;
};

size_t Set::GetMaxPower(){
    return _maxPower;
};

bool Set::operator==(const Set& tmp) { 
        return _maxPower == tmp._maxPower && _bitField == tmp._bitField; 
};

Set& Set::operator=(const Set& tmp) { 
        if (this != &tmp) {
            _maxPower = tmp._maxPower; 
            _bitField = tmp._bitField;
        }
        return *this; 
};



bool Set::IsMemder(uint64_t elem) {
    return _bitField.GetBit(elem);
}

/*std::vector<uint64_t> Set::GetPrimary() { 
    std::vector<uint64_t> prost; 
    Set copy(*this);
    size_t size_copy = copy.GetMaxPower(); 

    for (size_t i = 2; i <= int(sqrt(size_copy)); ++i) { 
        if (copy._bitField.GetBit(i)) { 
            for (size_t j = i * i; j < size_copy; j += i) { 
                copy.DeleteElem(j); 
            }
            prost.push_back(i); 
        }
    }
    return prost; 
}*/
std::vector<uint64_t> Set::GetPrimary() {
    std::vector<uint64_t> prost;
    Set copy(*this); // Создаем копию текущего сета
    
    size_t size_copy = copy.GetMaxPower(); 

    for (size_t i = 2; i < size_copy; ++i) {
        if (copy._bitField.GetBit(i)) { 
            prost.push_back(i); 
            for (size_t j = i * i; j < size_copy; j += i) {
                copy.DeleteElem(j);
            }
        }
    }
    
    return prost;
}

//вставить элемент 
void Set::InserElem(uint64_t elem) {
        _bitField.SetBit(elem);
}

//удалить элемент
void Set::DeleteElem(uint64_t elem) {
        _bitField.ClrBit(elem);
}




