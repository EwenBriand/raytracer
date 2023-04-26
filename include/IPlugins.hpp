/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** IPlugins
*/

#ifndef IPLUGINS_HPP_
    #define IPLUGINS_HPP_

enum pluginType{
    PRIMITIVE,
    LIGHT,
};

class IPlugins {
    public:
        ~IPlugins() = default;
        virtual int getType() const = 0;
        virtual void setType(pluginType type) = 0;
    protected:
        int _type;
};

#endif /* !IPLUGINS_HPP_ */
