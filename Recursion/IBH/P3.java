import java.util.*;

public class P3 {
    public static void displayStack(Stack<Integer> stack){
        int n = stack.size();

        while(n-- > 0){
            System.out.print(stack.pop() + " ");
        }

        System.out.println();
    }

	public static void insertElement(Stack<Integer> stack, int element){
		if(stack.isEmpty()){
			stack.push(element);
			return;
		}

		if(stack.peek() > element){
			stack.push(element);
		} else{
			int top = stack.pop();
			insertElement(stack, element);
			stack.push(top);
		}
	}

	public static void sortStack(Stack<Integer> stack) {
		if(stack.size() == 1){
			return;
		}

		int top = stack.pop();
		sortStack(stack);
		insertElement(stack, top);
	}

    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        stack.push(10);
        stack.push(1000);
        stack.push(100);
        stack.push(20);
        stack.push(1);
        
        sortStack(stack);
        displayStack(stack);  //Empties stack
    }
}
