//Allan Sur prog 1; 310 Manju 8:00AM TTH; 821444631
package Driver;
import java.util.*;
import Container.LLStack;
import Data.DataClass;
import Container.StackQ;

public class Driver {

	public static void main(String[] args) {
		StackQ queue = new StackQ();
		String choice, name;
		int id = 0;
		Scanner input = new Scanner(System.in);
		
			
		do {
			System.out.println("///Queue implemented by linkedlists & stack MENU///\n");
			System.out.println("Please pick a letter to choose an option");
			System.out.println("A. Enqueue in the queue");
			System.out.println("B. Dequeue from the queue");
			System.out.println("C. Peek from the queue");
			System.out.println("D. Display the queue");
			System.out.println("E. Display enQStack and deQStack");
			System.out.println("F. Display Size of the queue");
			System.out.println("G. Exit the program\n");
			
			choice = input.nextLine();
			choice = choice.toLowerCase();
			
			if(choice.equals("a") || 
					choice.equals("b") || 
					choice.equals("c") || 
					choice.equals("d") || 
					choice.equals("e") || 
					choice.equals("f") || 
					choice.equals("g")) {
			switch(choice) {
			
			case "a": 
				System.out.println("Please enter the name of the person\n");
				name = input.nextLine();
				try {
					System.out.println("Please enter the ID of the person\n");
				id = input.nextInt();
				}catch(Exception e) {
					System.out.println("Please enter an integer only.\n");
					break;
				}
				DataClass newData = new DataClass(name, id);
				queue.enQ(newData);
				System.out.println(name + " with ID#: " + id + " has been enqued\n");
				input.nextLine();
				break;
			
			case "b":
				System.out.println("The person " + queue.peek() + " has been dequeued\n");
				queue.deQ();
			    break;
			
			case "c": 
				if(queue.peek() != null) {
				System.out.println("The queue peeked " + queue.peek() + "\n");
				}
			     break;
			
			case "d":
				System.out.println("/FRONT OF QUEUE/\n");
				System.out.println(queue.toString());
				System.out.println("/BACK OF QUEUE/\n");
			    break;
			
			case "e":
				if(queue.isEmpty() != true) {
				if(queue.getenQStack().isEmpty() != true) {
					
				System.out.println("Now displaying Enqueue\n");
				System.out.println(queue.getenQStack().toString());
				
				}
				else if(queue.getenQStack().isEmpty() == true) {
					System.out.println("The enQueue stack is empty");
				}
				if(queue.getdeQStack().isEmpty() != true) {
				System.out.println("Now displaying Dequeue\n");
				System.out.println(queue.getdeQStack().toString());
				}
				else if(queue.getdeQStack().isEmpty() == true) {
					System.out.println("The deQueue stack is empty");
				}
				
				break;
				}
				System.out.println("Both stacks are empty\n");
			    break;
			    
			case "f":
				int size = queue.getenQStack().getStackSize() + queue.getdeQStack().getStackSize();
				if(size != 0) {
				    System.out.println(" The queue is has a size of: " + size + "\n");
				}
				else if (size == 0) {
					System.out.println("The queue is currently empty\n");
				}
				break;
				
			case "g":
				System.out.println("Thank you for using the program, goodbye\n");
				choice = "g";
				break;
			}
			}
			else {
				System.out.println("Please choose a correct character, either upper or lowercase.\n");
			}
			
		}while(choice != "g" );
		

	}

}
