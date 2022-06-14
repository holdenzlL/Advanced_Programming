package com.advprog.factory.simplefactory;

import com.advprog.factory.pojo.AbstractPizza;
import com.advprog.factory.util.MakePizza;
import com.advprog.factory.pojo.CapicciosaPizza;
import com.advprog.factory.pojo.MargheritaPizza;

public class PizzaStore {
    public AbstractPizza Serve(String pizzaName){
        switch (pizzaName){
            case "Margherita":
                return new MargheritaPizza();
            case "Capicciosa":
                return new CapicciosaPizza();
            default:
                System.out.println("Sorry, no such kind of pizza :(");
                return null;
        }
    }
}
