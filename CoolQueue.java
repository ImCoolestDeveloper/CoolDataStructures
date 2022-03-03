/*
Simple Queue made in my own way in one day
*/
class Queue<T> {
	static final int MAX_ELEMENTS = 100;
	private T[] vals; 
	private int front;
	private int rear;
	@SuppressWarnings("unchecked")
	Queue() {
		vals=(T[])new Object[MAX_ELEMENTS];
		front=MAX_ELEMENTS-2;
		rear=MAX_ELEMENTS-1;
	}
	void enqueue(T v){
		if (isEmpty()){
			front=MAX_ELEMENTS-1;
			rear=MAX_ELEMENTS;
		}
		if ((rear==0&&front!=MAX_ELEMENTS-1)) shiftToEnd();

		if (rear!=0) {
			rear--;
			vals[rear] = v;
		}
	}
	void dequeue(){
		if (!isEmpty()) {
			vals[front] = null;
			front--;
		}
	}
	private void shiftToEnd() {
		if (front!=MAX_ELEMENTS-1) {
			int i;
			for (i=0;i<=(front-rear);i++) {
				vals[MAX_ELEMENTS-i-1] =vals[front-i];
				vals[front-i] = null;
			}
			front=MAX_ELEMENTS-1;
			rear=MAX_ELEMENTS-i;
		}
	}
	int getSize() {
		if (isEmpty()) return 0;
		return front-rear+1;
	}
	boolean isFull() {return (rear==0 && front==MAX_ELEMENTS-1);}
	boolean isEmpty() {return (rear==front+1);}
	T getFront() {
		if (front==-1) return null;
		return vals[front];
	}
	T getRear() {
		if (rear==-1) return null;
		return vals[rear];
	}
	public String toString(){
		String s = "[ ";
		if(isEmpty()) s+=" ";
		else if (rear<=front){
			for(int i=rear;i<=front;i++) s+=vals[i].toString()+" ";
		}
		s+="]";
		return s;
	}
}

class CoolQueue {
	public static void main(String args[]) {
		Queue<Integer> q = new Queue<Integer>();
		q.enqueue(10);
		q.enqueue(20);
		q.dequeue();
		q.enqueue(30);
		q.enqueue(40);
		System.out.println(q);
		System.out.println("Size: "+q.getSize());
		System.out.println("Rear: "+q.getRear());
		System.out.println("Front: "+q.getFront());
		System.out.println("Bye!");
	}
}