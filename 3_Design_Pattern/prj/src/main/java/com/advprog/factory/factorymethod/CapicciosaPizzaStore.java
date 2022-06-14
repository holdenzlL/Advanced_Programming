package com.advprog.factory.factorymethod;

import com.advprog.factory.pojo.AbstractPizza;
import com.advprog.factory.pojo.CapicciosaPizza;
import com.advprog.factory.util.MakePizza;

public class CapicciosaPizzaStore extends PizzaHeadquarter{
    @Override
    public AbstractPizza Serve() {
        return new CapicciosaPizza();
    }
}
