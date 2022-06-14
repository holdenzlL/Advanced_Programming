package com.advprog.factory.abstractfactory;

import com.advprog.factory.pojo.AbstractCalzone;
import com.advprog.factory.pojo.AbstractPizza;
import com.advprog.factory.pojo.VeganCalzone;
import com.advprog.factory.pojo.VeganPizza;

public class VeganFoodStore extends AbstractFoodStore{
    @Override
    public AbstractPizza ServePizza() {
        return new VeganPizza();
    }

    @Override
    public AbstractCalzone ServeCalzone() {
        return new VeganCalzone();
    }
}
