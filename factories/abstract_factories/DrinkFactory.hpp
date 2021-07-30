#pragma once

#include "HotDrink.hpp"
#include "HotDrinkFactory.hpp"
#include <map>
#include <memory>

using namespace std;

class DrinkFactory {
    map<string, unique_ptr<HotDrinkFactory>> hot_factories;

public:
    DrinkFactory() {
        hot_factories["coffee"] = make_unique<CoffeeFactory>();
        hot_factories["tea"] = make_unique<TeaFactory>();
    }

    unique_ptr<HotDrink> make_drink(const string& name) {
        auto drink = hot_factories[name]->make();
        drink->prepare(100);
        return drink;
    }
};