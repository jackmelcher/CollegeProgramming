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
 * Filename : Rational.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
public class Rational {

	public int numer;
	public int denom;
	
	public Rational(){
		numer = 0;
		denom = 1;
	}
	public Rational(int aNumer, int aDenom) {
		numer = aNumer;
		denom = aDenom;
	} 
	
	//(this.numer / this.denom) + (b.numer / b.denom) = ((this.numer * b.denom) / (this.denom * b.denom)) + ((b.numer * this.denom) / (b.denom * this.denom))
	public Rational plus(Rational b) {
		Rational temp = new Rational();
			
		temp.numer = this.numer * b.denom + b.numer * this.denom;
		temp.denom = this.denom * b.denom;
		
		return temp;
	}
	
	//(this.numer / this.denom) - (b.numer / b.denom) = ((this.numer * b.denom) / (this.denom * b.denom)) - ((b.numer * this.denom) / (b.denom * this.denom))
	public Rational minus(Rational b) {
		Rational temp = new Rational();
		
		temp.numer = this.numer * b.denom - b.numer * this.denom;
		temp.denom = this.denom * b.denom;
		
		return temp;
	}
	
	//(this.numer / this.denom) * (b.numer / b.denom) 
	public Rational mult(Rational b) {
		Rational temp = new Rational();
		
		temp.numer = this.numer * b.numer;
		temp.denom = this.denom * b.denom;
		
		return temp;
	}
	
	//(this.numer / a.denom) / (b.numer / b.denom) = (this.numer / this.denom) * (b.denom / b.numer) 
	public Rational div(Rational b) {
		Rational temp = new Rational();
		
		temp.numer = this.numer * b.denom;
		temp.denom = this.denom * b.numer;
		
		return temp;
	}
	
}
