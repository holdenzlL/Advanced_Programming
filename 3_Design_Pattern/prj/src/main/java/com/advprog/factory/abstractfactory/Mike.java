package com.advprog.factory.abstractfactory;

import com.advprog.factory.pojo.AbstractCalzone;
import com.advprog.factory.pojo.AbstractPerson;
import com.advprog.factory.pojo.AbstractPizza;

public class Mike extends AbstractPerson {
    public void EatCalzone(AbstractCalzone calzone){
        System.out.println("I ate a calzone");
    }

    public AbstractPizza OrderPizza(AbstractFoodStore foodStore){
        return foodStore.ServePizza();
    }

    public AbstractCalzone OrderCalzone(AbstractFoodStore foodStore){
        return foodStore.ServeCalzone();
    }
}
