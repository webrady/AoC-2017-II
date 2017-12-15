package day4;

import java.util.Scanner;
import java.io.File;
import java.util.ArrayList;

public class Day4{
    public static void main(String args[]){
        Scanner file = null;
        try{
            file = new Scanner(new File("input.txt"));
        }
        catch(Exception e){
            
        }
        //Goes line by line detecting if its a valid passphrase (PART 1) and anagram free phrases (PART 2)
        int validPhrases = 0;
        int anagramFree = 0;
        //Gets each phrase into a list
        while(file.hasNext()){
            String line = file.nextLine();
            String phrase = "";
            ArrayList<String> passPhrases = new ArrayList<>();
            for(int i = 0;i < line.length();i++){
                if(line.charAt(i) == ' '){
                    passPhrases.add(phrase);
                    phrase = "";
                }
                else{
                    phrase += line.charAt(i);
                    if(i == line.length() - 1){
                        passPhrases.add(phrase);
                        phrase = "";
                    }
                }
            }
            //Tests each phrase against other phrases in the pass phrase to test validity
            for(int i = 0;i < passPhrases.size();i++){
                for(int j = i + 1;j < passPhrases.size();j++){
                    if(passPhrases.get(i).equals(passPhrases.get(j))){
                        validPhrases--;
                        anagramFree--;
                        j = passPhrases.size();
                        i = passPhrases.size();
                    }
                    else if(isAnagram(passPhrases.get(i),passPhrases.get(j))){
                        anagramFree--;
                        j = passPhrases.size();
                        i = passPhrases.size();
                    }
                }
            }
            validPhrases++;
            anagramFree++;
        }
        System.out.println(validPhrases);
        System.out.println(anagramFree);
    }
    
    //Returns whether or not two strings are anagrams of each other (PART 2)
    public static boolean isAnagram(String s1,String s2){
        boolean anagram = false;
        if(s1.length() != s2.length()){
            anagram = false;
        }
        else{
            for(int i = 0;i < s1.length();i++){
                int occurances = 0;
                //Counts how many times a letter appears
                for(int j = 0;j < s1.length();j++){
                    if(s1.charAt(i) == s1.charAt(j)){
                        occurances++;
                    }
                }
                for(int j = 0;j < s1.length();j++){
                    if(s1.charAt(i) == s2.charAt(j)){
                        occurances--;
                    }
                }
                if(occurances == 0){
                    anagram = true;
                }
                else{
                    anagram = false;
                    break;
                }
            }
        }
        return anagram;
    }
}