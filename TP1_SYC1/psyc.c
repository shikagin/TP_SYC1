#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    //L'tilisation de la commande  Execl!

   // printf("Avant excel1 \n");

    // Création du premier processus fils avec fork
    
    int pid = fork();  // fork 1

    // Si fork échoue, afficher un message d'erreur
    if (pid < 0)
    {
        printf("ERR à la création de fils \n");
        exit(EXIT_FAILURE);  // Terminer le programme en cas d'échec
    }
    else
    {
        // Si on est dans le processus fils (pid == 0)
        if (pid == 0)
        {
            // Exécution de la commande gcc pour compiler prog1.c en prog1.o 
            //creation d'objet prog1.o 

            if (execl("/usr/bin/gcc", "gcc", "-c", "prog1.c", "-o", "prog1.o", NULL) == -1)
            {
                printf("execl1 a échoué \n"); // Si execl échoue

                exit(EXIT_FAILURE); // Terminer le processus fils en cas d'échec
            }
        }
        else
        {
            // Attente de la fin du processus fils
            int status; // c'est le code de retour 

            waitpid(pid, &status, 0); 

            // Vérification de la sortie normale du processus fils
            if (WIFEXITED(status))
            {
                int code = WEXITSTATUS(status); //recuperer l'etat de retour

                if (code == 0)
                {
                    printf("Fin normale de l'exécution \n");
                }
                else
                {
                    printf("ERR d'exécution \n");
                }
            }
            else
            {
                printf("Fin anormale d'exécution \n");
            }
        }
    }

    // printf("Avant excel2 \n");

    // Création du second processus fils avec fork

    pid = fork(); // fork 2

    // Si fork échoue, afficher un message d'erreur
    if (pid < 0)
    {
        printf("ERR à la création de fils \n");
        exit(EXIT_FAILURE);
    }
    else
    {
        // Si on est dans le processus fils (pid == 0)

        if (pid == 0)
        {
            // Exécution de la commande gcc pour générer l'exécutable prog1 à partir de prog1.o
            if (execl("/usr/bin/gcc", "gcc", "prog1.o", "-o", "prog1", NULL) == -1)
            {
                printf("execl2 a échoué \n");
                exit(EXIT_FAILURE); // Terminer le processus fils en cas d'échec
            }
        }
        else
        {
            // Attente de la fin du processus fils

            int status; //le code de retour

            waitpid(pid, &status, 0);

            // Vérification de la sortie normale du processus fils
            if (WIFEXITED(status))
            {
                int code = WEXITSTATUS(status);

                if (code == 0)
                {
                    printf("Fin normale de l'exécution \n");
                }
                else
                {
                    printf("ERR d'exécution \n");
                }
            }
            else
            {
                printf("Fin anormale d'exécution \n");
            }
        }
    }

    // printf("Avant excel3 \n");

    // Création du troisième processus fils avec fork
    pid = fork(); //fork 3

    // Si fork échoue, afficher un message d'erreur
    if (pid < 0)
    {
        printf("ERR à la création de fils \n");
        exit(EXIT_FAILURE);
    }
    else
    {
        // Si on est dans le processus fils (pid == 0)
        if (pid == 0)
        {
            // Exécution de l'exécutable prog1
            if (execl("./prog1", "prog1", NULL) == -1)
            {
                printf("execl3 a échoué \n");
                exit(EXIT_FAILURE); // Terminer le processus fils en cas d'échec
            }
        }
        else
        {
            // Attente de la fin du processus fils
            int status; // le code de retour
            waitpid(pid, &status, 0);

            // Vérification de la sortie normale du processus fils
            if (WIFEXITED(status))
            {
                int code = WEXITSTATUS(status);
                if (code == 0)
                {
                    printf("Fin normale de l'exécution \n");
                }
                else
                {
                    printf("ERR d'exécution \n");
                }
            }
            else
            {
                printf("Fin anormale d'exécution \n");
            }
        }
    }

    return 0;
}
