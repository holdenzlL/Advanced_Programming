package com.advprog.factory.abstractfactory;

import com.advprog.factory.factorymethod.HawaiiPizzaStore;
import com.advprog.factory.factorymethod.MargheritaPizzaStore;

public class ApplicationAbstractFactory{
    public static void main(String[] args) {

        // Here is Mike
        Mike mike = new Mike();

        // If there is a new food store for meat lover in our town
        MeatLoverFoodStore meatLoverFoodStore = new MeatLoverFoodStore();
        // And Mike is a meat lover, he can go into this food store
        // order pizza
        mike.EatPizza(mike.OrderPizza(meatLoverFoodStore));
        // or order calzone
        mike.EatCalzone(mike.OrderCalzone(meatLoverFoodStore));

        // And If there is a new food store for vegetarian in our town
        VeganFoodStore veganFoodStore = new VeganFoodStore();
        // Mike today is doing vegan style, so he can go into this food store
        // order pizza
        mike.EatPizza(mike.OrderPizza(veganFoodStore));
        // or order vegan calzone
        mike.EatCalzone(mike.OrderCalzone(veganFoodStore));

    }
}
