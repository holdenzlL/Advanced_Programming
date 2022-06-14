package com.advprog.factory.simplefactory;


public class ApplicationSimpleFactory {
    public static void main(String[] args) {

        // Here is Mike
        Mike mike = new Mike();
        // He ordered a pizza and then eat it
        mike.EatPizza(mike.Order("Margherita"));

    }
}
