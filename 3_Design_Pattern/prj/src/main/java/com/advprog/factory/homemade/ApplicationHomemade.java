package com.advprog.factory.homemade;

public class ApplicationHomemade {
    public static void main(String[] args) {

        // here is a person called mike
        Mike mike = new Mike();

        mike.EatPizza(mike.MakePizza("Margherita"));

    }
}
