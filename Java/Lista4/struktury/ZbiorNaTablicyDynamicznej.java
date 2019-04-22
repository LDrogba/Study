package struktury;

/**
 * Klasa przechowujaca pary w tablicy o dynamicznym rozmiarze, dziedziczy po klasie ZbiorNaTablicy
 */
public class ZbiorNaTablicyDynamicznej extends ZbiorNaTablicy{
    /**
     * Tworzy obiekt o rozmiarze startowym - 2
     */
    public ZbiorNaTablicyDynamicznej(){
        Array = new Para[2];
    }

    private ZbiorNaTablicyDynamicznej(int size) throws Exception {
        super(size);
    }

    /**
     * Wstawia nowa pare do zbioru, w przypadku gdy zbior zostal juz wczesniej zapelniony, jego rozmiar zostaje dwukrotnie
     * powiekszony
     * @param p - nowa para ktora bedzie wstawiona do zbioru
     * @throws Exception - blad nigdy nie zostanie wyrzucony, jednak metoda jest dziedziczona i w nad klasie moze ona
     * zwrocic bledy
     */
    @Override
    public void wstaw(Para p) throws Exception {
        for(int i=0; i<Array.length; i++){
            if (Array[i] == null) {
                Array[i] = p;
                return;
            }
            if (p.klucz == Array[i].klucz)
                throw new Exception("Nie moze byc dwoch par z takim samym kluczem");
        }

        ZbiorNaTablicyDynamicznej new_col = new ZbiorNaTablicyDynamicznej(Array.length * 2);

        for(Para i_p : Array){
            new_col.wstaw(i_p);
        }

        new_col.wstaw(p);
        this.Array = new_col.Array;
    }

    @Override
    public void czysc(){
        Array = new Para[2];
    }
}
