package com.advprog.factory.homemade;

import com.advprog.factory.pojo.AbstractPerson;
import com.advprog.factory.pojo.AbstractPizza;
import com.advprog.factory.pojo.CapicciosaPizza;
import com.advprog.factory.pojo.MargheritaPizza;

public class Mike extends AbstractPerson {

    public AbstractPizza MakePizza (String pizzaName){
        switch (pizzaName){
            // If Mike want to make a Margherita Pizza by myself
            // Mike, need to new the object by himself
            case "Margherita":
                MargheritaPizza margheritaPizza = new MargheritaPizza();
                return margheritaPizza;
            // If Mike want to make a Capicciosa Pizza by myself
            // Mike, need to new the object by himself
            case "Capicciosa":
                CapicciosaPizza capicciosaPizza = new CapicciosaPizza();
                return capicciosaPizza;
            default:
                return null;
        }
    }
}



