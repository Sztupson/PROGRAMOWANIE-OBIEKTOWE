
public class Main
{
	public static void main(String[] args) {
		boolean b = 2 > 1;
		
		if (b) {
		    System.out.println("TTTTTTT");
		}
		/*
		byte - 8 bitów
		char - 16 bitów
		short - 16 bitów
		int - 32 bity
		long - 64 bity
		*/
		
		byte b1 = 64;
		
	    System.out.println(b1);
	    
	    b1 = 127;
	    
	    System.out.println(b1);
	    
	    char c = 'a';
	    
	    System.out.println(c);
	    
	    c = '\u0104';
	    
	    System.out.println(c);
	    
	    /* 
	    float - 32b
	    double - 64b
	    */
	    
	    float f = 1.2f;
	    Float ff = 3.4f;
	    Float ff2 = 1.1f;
	    
	    //System.out.println(f.toString());
	    System.out.println((int)Character.MAX_VALUE);
	    System.out.println(Float.MAX_VALUE);
	    System.out.println(ff.toString());
	    System.out.println(ff + ff2);
	    
	    long l = 123_456_789_1011L;
	    System.out.println(Long.MAX_VALUE);
	    
		
	}
}
