package com.advprog.factory.factorymethod;

import com.advprog.factory.pojo.AbstractPizza;
import com.advprog.factory.pojo.HawaiiPizza;
import com.advprog.factory.util.MakePizza;

public class HawaiiPizzaStore extends PizzaHeadquarter{
    @Override
    public AbstractPizza Serve() {
        return new HawaiiPizza();
    }
}
