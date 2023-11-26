import java.lang.Math;
class keyexchange{
    public static void main(String args[])
    {
        int p = 23;
        int g = 5;

        int x= 4;
        int y = 3;
        
        double aliceSends = Math.pow(g,x) % p;
        double aliceComputes = Math.pow(aliceSends,y) % p;
        
        double bobSends = Math.pow(g,y) % p;
        double bobComputes = Math.pow(bobSends,x) % p;

        double sharedSecret = Math.pow(g,(x*y)) % p;

        System.out.println("Simulation of Dieffel Heilmann algorithm ");

        System.out.println("Alice sends = Math.pow(g,x) % p"+aliceSends);
        System.out.println("Alice computes = Math.pow(alicesends,y) % p" + aliceComputes);
        System.out.println("bob sends = Math.pow(g,y) % p" + bobSends);
        System.out.println("Alice sends = Math.pow(bobcomputes,x) % p" +bobComputes);

        if ((aliceSends == sharedSecret) && (aliceComputes == bobComputes))
        {
            System.out.println("Success Shared secrets match" + sharedSecret);

        }
        else
        {
            System.out.println("does not match");
        }

    }
}