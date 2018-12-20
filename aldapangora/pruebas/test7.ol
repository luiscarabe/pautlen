main
{

    int v1, v2, v3;
    boolean v4;

    function int f1 (boolean pf1)
    {
        int vl1;

        vl1 = 1;
        v1 = 40;

        if (pf1)		//CASO 24: SE BUSCA UN ID NO CUALIFICADO (pf1) DEFINIDO EN UNA FUNCIÓN GLOBAL DESDE LA MISMA FUNCIÓN
					// Y SÍ QUE ESTÁ ==> OK
	{
            vl1=v1+2;

	}
	    return vl1;
    }
    v1 = 1;
    v4 = true;
    v2 = f1 (v4);

    v3 = f1 (false);


    printf v2;
    printf v4;
}
