package com.advprog.factory.factorymethod;

public class ApplicationFactoryMethod {
    public static void main(String[] args) {

        // Here is Mike
        Mike mike = new Mike();


        // If there is a Margherita Pizza store in his town
        MargheritaPizzaStore margheritaPizzaStore = new MargheritaPizzaStore();
        // Whenever he wants Margherita Pizza, he can order
        mike.EatPizza(mike.Order(margheritaPizzaStore));

        // If there is a Capicciosa Pizza store in his town
        CapicciosaPizzaStore capicciosaPizzaStore = new CapicciosaPizzaStore();
        // Whenever he wants Capicciosa Pizza, he can order
        mike.EatPizza(mike.Order(capicciosaPizzaStore));

        // Now, if there is a new Hawaii pizza store
        HawaiiPizzaStore hawaiiPizzaStore = new HawaiiPizzaStore();
        // Whenever he want Hawaii Pizza, he can order
        mike.EatPizza(mike.Order(hawaiiPizzaStore));

        // You don't need to new pizza object by yourself
        // But to get the pizza you want
        // You need to have the corresponding pizza strore
    }
}
