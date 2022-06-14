package com.advprog.factory.simplefactory;

import com.advprog.factory.pojo.AbstractPerson;
import com.advprog.factory.pojo.AbstractPizza;

public class Mike extends AbstractPerson {

    AbstractPizza Order(String pizzaName){

        // If there is a pizza store, Mike doesn't need to make pizza by himself
        // Whenever Mike wants to eat pizza, he just calls the pizza store
        // and tell them what kind of pizza he wants, then they will give him pizza

        PizzaStore pizzaStore = new PizzaStore();
        return pizzaStore.Serve(pizzaName);
    }
}
