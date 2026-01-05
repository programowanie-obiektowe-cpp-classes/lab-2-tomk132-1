#pragma once

#include "Resource.hpp"
#include <iostream>

class ResourceManager
{

public:
    ResourceManager() : res(new Resource) {};
    ~ResourceManager() { delete res; };
    ResourceManager(const ResourceManager& other) : res{new Resource(*other.res)} {};
    ResourceManager& operator=(const ResourceManager& other)
    {

        if (this == &other)
            return *this;

        Resource* nowy = new Resource{*other.res};
        delete this->res;
        this->res = nowy;

        return *this;
    };
    ResourceManager(ResourceManager&& other) noexcept : res{other.res} { other.res = nullptr; };

    ResourceManager& operator=(ResourceManager&& other) noexcept
    {

        if (this == &other) {
            return *this;
        };

        delete this->res;
        this->res = nullptr; 
        this->res = other.res; 
        other.res = nullptr;

        return *this;
    };

    double get() { return res->get(); };

private:
    Resource* res;
};