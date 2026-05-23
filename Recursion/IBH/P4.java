import java.util.*;

public class P4 {
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

		int top = stack.pop();
		insertElement(stack, element);
		stack.push(top);
	}

	public static void reverseStack(Stack<Integer> stack) {
		if(stack.isEmpty()){
			return;
		}

		int top = stack.pop();
		reverseStack(stack);
		insertElement(stack, top);
	}

    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        stack.push(5);
        stack.push(4);
        stack.push(3);
        stack.push(2);
        stack.push(1);
        
        reverseStack(stack);
        displayStack(stack); //Empties stack
    }
}
