etape 1: verifier l'argument, il doit y avoir un seul argument qui n'est pas NULL et est en .ber

etape 2: initialiser la mlx (da->mlx = mlx_init();)

etape 3: prendre toute les info de la map, par exemple remplire un int* avec les coordonne x et y des mur un autre avec les coordonne du player etc...

etape 4: verifier grace aux info la validiter de la map

	- La carte doit contenir 1 sortie, au moins 1 item et 1 position de départ.
	Si la map contient des doublons, vous devez afficher un message
	d’erreur.

	- La carte doit être de forme rectangulaire.

	- La carte doit être fermée en étant encadrée par des murs. Si ce n’est pas le cas, le
	programme retourne une erreur.

	- Vous devez vérifier s’il existe un chemin valide (i.e. qu’il est possible d’emprunter)
	dans la carte.

	- Vous devez pouvoir parser tout type de carte du moment qu’elle respecte les règles
	énoncées ci-dessus

	pour des exemple de map non valide regarder les map error dans le fichier miniber.

etape 5: faire le pathfinding pour verifier si la map est faisable

etape 6: une fois tout ca fait vous pouver initialiser les iamge et la fenettre

etape 7: mettre les iamge sur la fenettre

etape 8: cree les hooks pour faire deplacer le perso et gerer l'exit

etape eternel: n'oublie pas de toujours proteger les malloc et de free tout ce qui a ete malloc en cas d'erreur ni plus ni moin