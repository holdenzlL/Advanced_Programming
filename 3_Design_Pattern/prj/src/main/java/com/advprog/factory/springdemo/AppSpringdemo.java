package com.advprog.factory.springdemo;

import org.springframework.context.support.ClassPathXmlApplicationContext;

public class AppSpringdemo {

    //IOC

    public static void main(String[] args) {

        ClassPathXmlApplicationContext context = new ClassPathXmlApplicationContext("applicationContext.xml");
        SpringPizza springPizza = (SpringPizza) context.getBean("springPizza");
        springPizza.print();

    }
}
