
// class EagerSingleton {
//     private static final EagerSingleton instance = new EagerSingleton();
//     private EagerSingleton() {
//         System.out.println("Construct...");
//     }
    
//     private int x = 567;
//     public static EagerSingleton getInstance() { 
//         return instance; 
        
//     }

//     public void setX(int x) {
//         this.x = x;
//     }
    
//     public int getX() {
//         return x;
//     }
// }



// public class Main
// {
// 	public static void main(String[] args) {
		
// 		EagerSingleton s1 = EagerSingleton.getInstance();
// 		EagerSingleton s2 = EagerSingleton.getInstance();
		
// 		s1.setX(123);
// 		System.out.println(s2.getX());
// 	}
// }



