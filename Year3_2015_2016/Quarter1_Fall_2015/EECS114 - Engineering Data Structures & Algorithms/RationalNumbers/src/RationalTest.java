/**
 * Course: EECS 114 Fall 2015
 *
 * First Name: Jack
 * Last Name: Melcher
 * Lab Section: 1A
 * email address: jmelcher@uci.edu
 *
 *
 * Assignment: lab1
 * Filename : RationalTest.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
public class RationalTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Rational b =  new Rational(); // b = 0/1 
		Rational a = new Rational(1, 2); // a = 1/2 
		
		Rational c = a.plus(b); //it returns (a.numer / a.denom) + (b.numer / b.denom) and stores the value in c
		System.out.println(a.numer+"/"+a.denom+" + "+ b.numer+"/"+b.denom + " = " + c.numer+"/"+c.denom);
		
		//Add more test code here 
		Rational d = new Rational(2, 3); // d = 2/3 
		Rational e = new Rational(3, 4); // e = 3/4
		Rational f = new Rational(4, 5); // f = 4/5

		
		Rational g = a.minus(d); //it returns (a.numer / a.denom) - (b.numer / b.denom) and stores the value in g
		System.out.println(a.numer+"/"+a.denom+" - "+ d.numer+"/"+d.denom + " = " + g.numer+"/"+g.denom);
		
		Rational h = a.mult(e); //it returns (a.numer / a.denom) * (b.numer / b.denom) and stores the value in h
		System.out.println(a.numer+"/"+a.denom+" * "+ e.numer+"/"+e.denom + " = " + h.numer+"/"+h.denom);
		
		Rational i = a.div(f); //it returns (a.numer / a.denom) / (b.numer / b.denom) and stores the value in i
		System.out.println(a.numer+"/"+a.denom+" / "+ f.numer+"/"+f.denom + " = " + i.numer+"/"+i.denom);
	}

}
