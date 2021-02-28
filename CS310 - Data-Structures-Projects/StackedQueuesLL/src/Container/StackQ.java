package Container;

import Interface.QueueSpecs;

public class StackQ<E> implements QueueSpecs<E>{
	
	private LLStack<E> enQStack;
	private LLStack<E> deQStack;
    //Constructor argument
	public StackQ(LLStack<E> stack1, LLStack<E> stack2) {
		enQStack = stack1;
		deQStack = stack2;
	}
	public StackQ() {
		this.enQStack = new LLStack<E>();
		this.deQStack = new LLStack<E>();
	}
	public LLStack<E> getenQStack(){
		return enQStack;
	}
	public LLStack<E> getdeQStack(){
		return deQStack;
	}
	
	@Override
	public boolean isEmpty() {
		if(enQStack.isEmpty() == true && deQStack.isEmpty() == true) {
			return true;
		}
		return false;
	}

	@Override
	public void emptyQueue() {
			enQStack.emptyStack();
			deQStack.emptyStack();
	}

	@Override
	public void enQ(E obj) {
			enQStack.push(obj);
			enQStack.setStackSize(enQStack.getStackSize() + 1);
	}

	@Override
	public E deQ() {
		E data;
		if(deQStack.isEmpty() == true) {
			while(enQStack.isEmpty() == false) {
				data = enQStack.pop();
				deQStack.push(data);
			}
		}
		data = deQStack.pop();
		enQStack.setStackSize(enQStack.getStackSize() - 1);
		return data;
	}

	@Override
	public E peek() {
		E data;
		if(deQStack.isEmpty() == true) {
			data = enQStack.peek();
			return data;
		}
		else {
		data = deQStack.peek();
		}
		return data;
	}
	
	@Override
	public String toString() {
		StringBuilder str = new StringBuilder();
		if(deQStack.isEmpty() != true) {
			str.append(deQStack.toString());
		}
		if(enQStack.isEmpty() != true) {
			str.append(enQStack.toString());
		}
		if(enQStack.isEmpty() == true && deQStack.isEmpty() == true) {
			System.out.println("The queue is empty\n");
		}
		return str.toString();
	}

}
