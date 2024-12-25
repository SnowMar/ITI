import go.*;

public class Main {
    public static void main(String[] args) {
        ExceptionThrower thrower = new ExceptionThrower();

        try {
            thrower.methodOne(-4);
        } catch (MyCustomException e) {
            System.out.println("Caught: " + e.getMessage());
        } finally {
            System.out.println("\nFinally block executed for methodOne.");
        }

        try {
            thrower.methodTwo(501);
        } catch (MyCustomException e) {
            System.out.println("Caught: " + e.getMessage());
        } finally {
            System.out.println("\nFinally block executed for methodTwo.");
        }

        try {
            thrower.methodThree(null);
        }catch(MyCustomException e){
            System.err.println("Caught: " + e.getMessage());
        }finally{
            System.out.println("\nFinally block executed for methodThree.");
        }
    }
}
