
public class Main {

    public static void main(String[] args) {

        Array<Integer> arr = new Array<>(10);

        for(int i = 0; i < 10; i ++){
            arr.addLast(i);
        }
        System.out.println(arr);

        arr.addLast(666);
        System.out.println(arr);

        arr.addFirst(-1);;
        System.out.println(arr);

        System.out.println(arr.get(2));

        arr.set(2, 10000);
        System.out.println(arr);

        arr.remove(4);
        System.out.println(arr);

        arr.removeFirst();
        System.out.println(arr);

        arr.removeLast();
        System.out.println(arr);

        arr.removeElement(5);
        System.out.println(arr);
    }
}
