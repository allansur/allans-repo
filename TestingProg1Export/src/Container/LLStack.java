package Container;

import Interface.StackSpecs;
public class LLStack<E> implements StackSpecs<E>{
	
	private Node<E> top;
	private int stackSize;
	
	
	
	public void setTop(Node<E> node) {
		top = node;
	}
	public void setStackSize(int size) {
		stackSize = size;
	}
	public int getStackSize() {
		return stackSize;
	}
	
	@Override
	public boolean isEmpty() {
		if(top == null) {
			return true;
		}
		return false;
	}
	
	@Override
	public void emptyStack() {
		top = null;
		stackSize = 0;
		
	}
	@Override
	public void push(E obj) {
		Node<E> curr = top;
		Node<E> temp = new Node<E>(obj);
		if(curr == null) {
			this.setTop(temp);
		}
		else if(curr != null) {
		while(curr.getNextNode() != null) {
			curr = curr.getNextNode();
		}
		curr.setNextNode(temp);
		}
		
	}
	@Override
	public E pop() {//this method doesn't seem to be working for me
		E value;
		Node<E> curr = top;
		if (this.isEmpty() == false){
			value = curr.getData();
			top = curr.getNextNode();
			return value;
		}
		value = null;
		return value;
	}
	@Override
	public E peek() {
		E value;
		Node<E> curr = top;
		if(this.isEmpty() != true) {
		value = curr.getData();
		return value;
		}
		System.out.println("The stack is currently empty\n");
		return null;
	}
	//constructor of an LLStack
	public LLStack(Node<E> head) {
		this.stackSize = 0;
		this.top = head;
	}
	public LLStack() {
		this.stackSize = 0;
		this.top = null;
	}
	@Override
	public String toString() {
		Node<E> curr = this.top;
		StringBuilder str = new StringBuilder();
			while (curr.getNextNode()!= null) {
				str.append(curr.getData() + " \n");
				curr = curr.getNextNode();
			}
			if(curr.getNextNode() == null) {
					str.append(curr.getData() );
				}
		
		return str.toString();
	}
	

}
