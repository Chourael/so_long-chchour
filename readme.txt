etape 1: verifier l'argument, il doit y avoir un seul argument qui n'est pas NULL et est en .ber

etape 2: initialiser la mlx (da->mlx = mlx_init();)

etape 3: mettre la map dans un char** pour l'utiliser
		parcourir le argv[1] pour compter le nombre de \n, le nombre de char* a faire sera = au nombre de \n + 1
		parcourir le argv[1] pour compter le nombre de char dans une ligne (la taille d'une ligne) et verifier aue toute les lignes fond la meme taille si ce n'est pas le cas renvoyer une erreur map non rectangulaire

etape 4: verifier grace a la map la validiter de la map

	- La carte doit contenir 1 sortie, au moins 1 item et 1 position de départ.
	Si la map contient des doublons, vous devez afficher un message
	d’erreur.
	il suffit de parcourire la map et compter le nombre de P, E et C, si P est different de 1 || E est different de 1 || C est inferieur a 1

	- La carte doit être de forme rectangulaire.
	deja verifier avant la creation du char** fullmap

	- La carte doit être fermée en étant encadrée par des murs. Si ce n’est pas le cas, le
	programme retourne une erreur.
	pour ca parcourire la premiere ligne donc jusqu'au premier \n si il y'a autre chose au'un '1' renvoyer l'erreur aproprier
	ensuite parcourire chaque tableau de fullmap et si un fullmap[i][0] != '1' ou fullmap[i][max] != '1' la map m'est pas entourer par des 1, renvoyer le message d'erreur aproprier

	pour des exemple de map non valide regarder les map error dans le fichier miniber.

etape 5: prendre toute les info de la map, par exemple remplire un int** avec les coordonne x et y des mur un autre avec les coordonne du player etc...

etape 6: faire le pathfinding pour verifier si la map est faisable

etape 7: une fois tout ca fait vous pouver initialiser les iamge et la fenettre

etape 8: mettre les iamge sur la fenettre

etape 9: cree les hooks pour faire deplacer le perso et gerer l'exit

etape eternel: n'oublie pas de toujours proteger les malloc et de free tout ce qui a ete malloc en cas d'erreur ni plus ni moin

ps: il y'a plusieur maniere de faire je decrit celle que j'ai fqit