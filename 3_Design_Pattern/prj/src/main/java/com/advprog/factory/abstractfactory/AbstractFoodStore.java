package com.advprog.factory.abstractfactory;

import com.advprog.factory.pojo.AbstractCalzone;
import com.advprog.factory.pojo.AbstractPizza;

public abstract class AbstractFoodStore {
    public abstract AbstractPizza ServePizza();
    public abstract AbstractCalzone ServeCalzone();
}
