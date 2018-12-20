main
{
	class A
	{
		int aiA1; boolean aiA2;
		function int msA1()
		{
			int vl1;

			printf 0;
			return 0;
		}
		function boolean msA2(int p1)
		{
			int vl1;

			printf 0;
			return false;
		}
	};
  class B inherits A
  	{
  		boolean aiB1; boolean aiB2;
  		function int msA1()
  		{
  			int vl1;

  			printf 10;
  			return 10;
  		}
  		function none msB1()
  		{
  			int vl1;

  			printf 10;
  			return none;
  		}
  		function none msB2(int p1)
  		{
  			int vl1;

  			printf 0;
  			return none;
  		}
  	};
    class C inherits A
    	{
    		int aiC1; int aiC2;
    		function int msA1()
    		{
    			int vl1;

    			printf 100;
    			return 100;
    		}
    		function boolean msA2(int p1)
    		{
    			int vl1;

    			printf 100;
    			return true;
    		}
        function boolean msC1(int p1ss; int p2)
        		{
        			int vl1;
        			int vl2;

        			printf 100;
        			return true;
        		}
        		function boolean msC2(int p1)
        		{
        			int vl1;

        			printf 100;
        			return true;
        		}
        	};

          class D inherits B, C
          	{
          		int aiD1; int aiD2;
          		function none msD1()
          		{
          			int vl1;

          			printf 0;
          			return none;
          		}
          		function int msD1(int p1; int p2;
                                       boolean p3; {D} p4)
          		{
          			int vl1;

          			printf 0;
          			return 1;
          		}
          	};

          	printf 0;


          }
