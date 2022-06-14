package com.advprog.factory.abstractfactory;

import com.advprog.factory.pojo.AbstractCalzone;
import com.advprog.factory.pojo.AbstractPizza;
import com.advprog.factory.pojo.MeatCalzone;
import com.advprog.factory.pojo.MeatPizza;
import com.advprog.factory.util.MakeCalzone;
import com.advprog.factory.util.MakePizza;

public class MeatLoverFoodStore extends AbstractFoodStore{
    @Override
    public AbstractPizza ServePizza() {
        return new MeatPizza();
        }

    @Override
    public AbstractCalzone ServeCalzone() {
        return new MeatCalzone();
    }
}
