main
{

    int v1, v2, v3;
    boolean v4;
    function int f1 (boolean pf1)
    {
        int vl1;

        vl1 = 1;

        if ((pf1 == true))		//CASO 24: SE BUSCA UN ID NO CUALIFICADO (pf1) DEFINIDO EN UNA FUNCIÓN GLOBAL DESDE LA MISMA FUNCIÓN
					// Y SÍ QUE ESTÁ ==> OK
	{
            vl1=v1+2;

	}
	    return vl1;
    }
    v1 = 1;
    v2 = f1 (true);

    v4 = false;

    v3 = f1 (v4);


    printf v2;
    printf v4;     
}
