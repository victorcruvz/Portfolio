
package javaapplication;

import javax.swing.JOptionPane;

public class JavaApplication {


    public static void main(String[] args) {
        
        int elementos;
        
        //Usar Integer para mostrar en ventana un dialogo y guardarlo como entero
        //Para Integer escribir "int" ctrl + space
        //Para JoptionPane escribir "jop" ctrl + space
        //Jop va dentro del Integer para poder mostrar y guardar en ventana
        elementos = Integer.parseInt(JOptionPane.showInputDialog("Cuantos valores tiene tu funcion: "));
        
        //Declaramos un arreglo para las constantes
        int[] constantes = new int[elementos];
        //Declaramos un arreglo para las variables
        char[] variables = new char[elementos];
        //Declaramos los signos de la funcion
        char[] signos = new char[elementos];
        
        //Captura de constantes
        JOptionPane.showMessageDialog(null, "Digita tus constantes");
        for(int i=0; i<elementos; i++){
            constantes[i] = Integer.parseInt(JOptionPane.showInputDialog((i+1)+". Digita la constante: "));
        }
        
        //Captura de signos
        JOptionPane.showMessageDialog(null, "Digita tus signos");
        for(int i=0; i<elementos; i++){
            signos[i] = JOptionPane.showInputDialog((i+1)+". Digute el signo: ").charAt(0);
        }
        
        //Captura de variables
        JOptionPane.showMessageDialog(null, "Digita tus variables");
        for(int i=0; i<elementos; i++){
            variables[i] = JOptionPane.showInputDialog((i+1)+". Digute la variable: ").charAt(0);
        }
        
        //Imprimir la duncion dada
        JOptionPane.showMessageDialog(null, "Tu funcion es: ");
            for(int j=0; j<elementos; j++){
            //  JOptionPane.showMessageDialog(null, constantes[j] + "" + variables[j]);
                System.out.print(signos[j] + "" + constantes[j] + "" + variables[j]);
        }
        
    }
    
}
