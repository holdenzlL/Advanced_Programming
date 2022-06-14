package com.advprog.factory.factorymethod;

import com.advprog.factory.pojo.AbstractPerson;
import com.advprog.factory.pojo.AbstractPizza;
import com.advprog.factory.simplefactory.PizzaStore;

public class Mike extends AbstractPerson {
    AbstractPizza Order(PizzaHeadquarter pizzaStore){
        return pizzaStore.Serve();
    }
}
