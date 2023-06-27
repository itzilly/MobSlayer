//
// Created by illyum on 6/26/2023.
//

#ifndef MOBSLAYER_GAMEOBJECT_HPP
#define MOBSLAYER_GAMEOBJECT_HPP


class GameObject {
public:
    void Update();
    void Render();
    virtual ~GameObject() {}   // Virtual destructor (important for proper memory deallocation)
};


#endif //MOBSLAYER_GAMEOBJECT_HPP
