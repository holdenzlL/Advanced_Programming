package com.advprog.factory.factorymethod;

import com.advprog.factory.pojo.AbstractPizza;
import com.advprog.factory.pojo.MargheritaPizza;
import com.advprog.factory.util.MakePizza;

public class MargheritaPizzaStore extends PizzaHeadquarter{
    @Override
    public AbstractPizza Serve() {
        return new MargheritaPizza();
    }
}
