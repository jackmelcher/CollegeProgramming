/**
 * Course: EECS 114 Fall 2015
 *
 * First Name: Jack
 * Last Name: Melcher
 * Lab Section: 1A
 * email address: jmelcher@uci.edu
 *
 *
 * Assignment: Assignment 1
 * Filename : Main.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyList list = new MyList();
		list.print();
		int tempSize = 0;
		
		System.out.println("");
		
		System.out.println("pushFront test");
		for(char i = 'a'; i < 'a'+10; i++){
			list.pushFront(i);
			list.print();
		}
		System.out.println("Size of List = "+list.size());
		System.out.println("");

		System.out.println("popFront test");
		tempSize = list.size();
		for(int i = 0; i < tempSize; i++){
			list.popFront();
			list.print();
		}
		System.out.println("Size of List = "+list.size());
		System.out.println("");

		System.out.println("pushBack test");
		for(char i = 'a'; i < 'a'+10; i++){
			list.pushBack(i);
			list.print();
		}
		System.out.println("Size of List = "+list.size());
		System.out.println("");

		System.out.println("popBack test");
		tempSize = list.size();
		for(int i = 0; i < tempSize; i++){
			list.popBack();
			list.print();
		}
		System.out.println("Size of List = "+list.size());
		System.out.println("");

		System.out.println("insertAtPos Test");
		list.insertAtPos(0,'x');
		list.print();
		list.insertAtPos(1,'y');
		list.print();
		list.insertAtPos(2,'z');
		list.print();
		System.out.println("Size of List = "+list.size());
		System.out.println("");

		System.out.println("insertAfter Test");
		list.insertAfter(0,'a');
		list.print();
		list.insertAfter(1,'b');
		list.print();
		list.insertAfter(list.size(),'c');
		list.print();
		System.out.println("Size of List = "+list.size());
		System.out.println("");

		System.out.println("insertBefore Test");
		list.insertBefore(0,'i');
		list.print();
		list.insertBefore(1,'j');
		list.print();
		list.insertBefore(2,'k');
		list.print();
		System.out.println("Size of List = "+list.size());
		System.out.println("");

		System.out.println("remove index Test");
		list.remove(0);
		list.print();
		list.remove(2);
		list.print();
		list.remove(4);
		list.print();
		list.remove(-1);
		list.print();
		list.remove(list.size());
		list.print();
		System.out.println("Size of List = "+list.size());
		System.out.println("");

		System.out.println("contains Test");
		System.out.println(""+list.contains('l'));
		System.out.println(""+list.contains('x'));
		System.out.println(""+list.contains('y'));
		System.out.println(""+list.contains('k'));
		System.out.println(""+list.contains('b'));
		list.print();
		System.out.println("");

		System.out.println("remove char Test");
		list.remove('l');
		list.print();
		list.remove('x');
		list.print();
		list.remove('y');
		list.print();
		list.remove('k');
		list.print();
		list.remove('b');
		list.print();
		System.out.println("Size of List = "+list.size());
		System.out.println("");

		System.out.println("removeAll Test");
		for(int i = 0; i < 3; i++){
			list.pushBack('a');
			list.pushBack('b');
			list.pushBack('c');
		}
		list.print();
		list.removeAll('a');
		list.print();
		list.removeAll('d');
		list.print();
		list.removeAll('b');
		list.print();
		list.removeAll('c');
		list.print();
		System.out.println("");


		//previous(Node) and next(Node) were implemented in remove(char) and function properly
		//System.out.println("previous Node Test");
		//System.out.println("next Node Test");
		
		System.out.println("get Test");
		list.pushBack('a');
		list.pushBack('b');
		list.pushBack('c');
		list.print();
		System.out.println("get(0) = "+list.get(0));
		System.out.println("get(1) = "+list.get(1));
		System.out.println("get(2) = "+list.get(2));
		System.out.println("");

		System.out.println("set Test");
		list.set(0,'d');
		list.print();
		list.set(1,'e');
		list.print();
		list.set(2,'f');
		list.print();
		System.out.println("");

		System.out.println("swap Test");
		list.swap(0, 1);
		list.print();
		list.swap(1, 2);
		list.print();
		list.swap(0, 2);
		list.print();
		System.out.println("");

		System.out.println("MyList copy charArray Test");
		char[] charArray = {'a','b','c','d','e','f','g','h'};
		MyList list1 = new MyList(charArray, charArray.length);
		list1.print();
		System.out.println("");

		System.out.println("MyList copy rhs Test");
		MyList list2 = new MyList(list1);
		list1.print();
		list2.print();
		System.out.println("");

		System.out.println("equals Test");
		System.out.println(""+list1.equals(list2));
		System.out.println(""+list.equals(list1));
		System.out.println("");

		System.out.println("toArray Test");
		charArray = list1.toArray();
		for(int i = 0; i < charArray.length; i++){
			System.out.print(""+charArray[i]);
		}
		System.out.print("\n");
		System.out.println("");
		
		System.out.println("reverse Test");
		list1.reverse();
		list1.print();
		System.out.println("");

		System.out.println("subList Test");
		MyList list3 = new MyList(list1);
		list3 = list2.subList(3, 7);
		list2.print();
		list3.print();
		System.out.println("");

		System.out.println("find char Test");
		System.out.println("find char 'a' in list2: "+list2.find('a'));
		System.out.println("find char 'e' in list2: "+list2.find('e'));
		System.out.println("find char 'i' in list2: "+list2.find('i'));
		System.out.println("");

		
		System.out.println("toString test");
		System.out.println("toString of list1: "+list1.toString());
		System.out.println("toString of list2: "+list2.toString());
		System.out.println("toString of list3: "+list3.toString());
		System.out.println("");

		System.out.println("find queryString Test");
		System.out.println("find list3 in list2: "+list2.find(list3));


	}

}
