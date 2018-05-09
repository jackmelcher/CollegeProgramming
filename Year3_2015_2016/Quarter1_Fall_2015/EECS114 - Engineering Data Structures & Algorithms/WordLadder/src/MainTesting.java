
public class MainTesting {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		//List testing
		SimpleList<Character> list = new SimpleList<Character>();
		list.print();
		
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
		
		System.out.println("set Test");
		list.setAt(0,'d');
		list.print();
		list.setAt(1,'e');
		list.print();
		list.setAt(2,'f');
		list.print();
		System.out.println("");
		
		System.out.println("toString test");
		System.out.println("toString of list: "+list.toString());
		System.out.println("");

		System.out.println("remove index Test");
		list.removeAt(1);
		list.print();
		list.removeAt(0);
		list.print();
		list.removeAt(4);
		list.print();
		list.removeAt(-1);
		list.print();
		list.removeAt(list.size()-1);
		list.print();
		System.out.println("Size of List = "+list.size());
		System.out.println("");
		
		//Stack testing
	    MyStack<String> stack = new MyStack<String>();
	    System.out.println(stack.top());
		stack.pop();
	    stack.push("hello");
		System.out.println(stack.top());
		stack.push("world!");
		System.out.println(stack.top());
		stack.push("You");
		System.out.println(stack.top());
		stack.push("suck!");
		System.out.println(stack.top());
		stack.pop();
		System.out.println(stack.top());
		stack.pop();
		System.out.println(stack.top());
		stack.pop();
		System.out.println(stack.top());
		stack.pop();
		
		//Queue testing
	    MyQueue<MyStack<String>> queue = new MyQueue<MyStack<String>>();
	    
	    
	    MyStack<String> stacktemp;
	    MyStack<String> stack1 = new MyStack<String>();
	    stack1.push("Hello1");
	    stack1.push("World1");
	    MyStack<String> stack2 = new MyStack<String>();
	    stack2.push("Hello2");
	    stack2.push("World2");
	    MyStack<String> stack3 = new MyStack<String>();
	    stack3.push("Hello3");
	    stack3.push("World3");
	    MyStack<String> stack4 = new MyStack<String>();
	    stack4.push("Hello4");
	    stack4.push("World4");

	    queue.push(stack1);
	    queue.push(stack2);
	    queue.push(stack3);
	    queue.push(stack4);
	    
	    stacktemp = queue.front();
		System.out.println(stacktemp.top());
		queue.front().pop();
		System.out.println(stacktemp.top());
	    queue.pop();
	    stacktemp = queue.front();
		System.out.println(stacktemp.top());
	    queue.pop();
		stacktemp = queue.front();
		System.out.println(stacktemp.top());
	    queue.pop();
		stacktemp = queue.front();
		System.out.println(stacktemp.top());
	    queue.pop();
	    queue.front();
	    queue.pop();

	}
}
