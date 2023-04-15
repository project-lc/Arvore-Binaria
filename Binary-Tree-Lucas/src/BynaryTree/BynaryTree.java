package BynaryTree;

import java.util.ArrayList;
public class BynaryTree<T extends Comparable <T>>{
    private Node<T> prim;
    private int folhas;

    public BynaryTree(){
        this.prim = null;
        this.folhas = 0;
    }

    public Node getPrim(){
        return this.prim;
    }

    private void setPrim(Node<T> elem){
        this.prim = elem;
    }

    public void insert(T elem){
        Node<T> novo = new Node<T>(elem);
        Node<T> noatual = this.getPrim();
        boolean parar = false;

        if(noatual == null){
            this.prim = novo;
        }
        else{
            while(!parar){
                if(novo.getValor().compareTo(noatual.getValor()) < 0){
                    //noatual = noatual.getEsq();
                    if(noatual.getEsq() == null){
                        noatual.setEsq(novo);
                        parar = true;
                        this.folhas += 1;
                    }else{
                        noatual = noatual.getEsq();
                    }
                } else if (novo.getValor().compareTo(noatual.getValor()) > 0) {
                    //noatual = noatual.getEsq();
                    if(noatual.getDir() == null){
                        noatual.setDir(novo);
                        parar = true;
                        this.folhas += 1;
                    }else{
                        noatual = noatual.getDir();
                    }
                }
                else{
                    System.out.printf("Valor %s ja existe na arvore.", noatual.getValor().toString()
                    );
                }
            }
        }
    }

    public int getFolhas(){
        return this.folhas;
    }

    //Terminar o walk
    public ArrayList<T> walkLevel () {
        ArrayList<T> lista = new ArrayList<T>();
        Node<T> actualnode = this.getPrim();
        int lvl = this.height();
        int actuallvl = 0;
        int actualelem = 0;

        lista.add(actualnode.getValor());

        while (actuallvl <= lvl) {
            if(actualnode.getEsq() != null){
                lista.add((T) actualnode.getEsq().getValor());
            }
            if(actualnode.getDir() != null) {
                lista.add((T) actualnode.getDir().getValor());
            }

            actuallvl++;
            actualelem++;

            actualnode = this.goTo(lista.get(actualelem));
        }

        return lista;
    }

    public Node<T> goTo(T elem){
        Node<T> ret = new Node<T>();
        boolean foundit = false;
        boolean parar = false;

        if (elem != null) {
            ret = this.getPrim();
            while (!parar) {
                if (elem.compareTo(ret.getValor()) < 0) {
                    ret = ret.getEsq();
                    if (ret.getValor() == null) {
                        parar = true;
                    }
                } else if (elem.compareTo(ret.getValor()) > 0) {
                    ret = ret.getDir();
                    if (ret.getValor() == null) {
                        parar = true;
                    }
                } else {
                    foundit = true;
                    parar = true;
                }
            }
        }

        return ret;
    }

    public boolean search(T elem) {
        boolean foundit = false;
        boolean parar = false;
        Node<T> noatual = this.getPrim();

        if (noatual != null) {
            while (!parar) {
                if (elem.compareTo(noatual.getValor()) < 0) {
                    noatual = noatual.getEsq();
                    if (noatual.getValor() == null) {
                        parar = true;
                    }
                } else if (elem.compareTo(noatual.getValor()) > 0) {
                    noatual = noatual.getDir();
                    if (noatual.getValor() == null) {
                        parar = true;
                    }
                } else {
                    foundit = true;
                    parar = true;
                }
            }
        }
        return foundit;
    }

    public void inOrder(Node<T> no) {
        if (no != null) {
            inOrder(no.getEsq());
            System.out.print(no.getValor() + " ");
            inOrder(no.getDir());
        }
    }

    public int height () {
        int hl = 0; //height left
        int hr = 0; //height right
        BynaryTree<T> bt2 = new BynaryTree<T>();
        Node<T> noaux = new Node<T>();

        if (this.getPrim() == null) {
            return -1;
        } else if ((this.getPrim().getEsq() == null) && (this.getPrim().getDir() == null)) {
            return 0;
        } else {
            noaux = this.getPrim().getEsq();
            bt2.setPrim(noaux);
            hl = hl + bt2.height();

            noaux = new Node<T>();
            noaux = this.getPrim().getDir();
            bt2.setPrim(noaux);
            hr = hr + bt2.height();

            if(hl > hr)
                return hl+1;
            else
                return hr+1;
        }
    }

    public Node<T> getMinor(){
        Node<T> min = new Node<T>();
        int h = this.height();
        int n = 0;

        min = this.getPrim();

        while((n <= h) && (min.getEsq() != null)){
            min = min.getEsq();
        }

        return min;
    }

    public Node<T> getMax(){
        Node<T> max = new Node<T>();
        int h = this.height();
        int n = 0;

        max = this.getPrim();

        while((n <= h) && (max.getDir() != null)){
            max = max.getEsq();
        }

        return max;
    }
}