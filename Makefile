PermissionsCheck: PermissionsCheck.c
	gcc -g -Wall -o PermissionsCheck PermissionsCheck.c

PermissionsChange: PermissionsChange.c
	gcc -g -Wall -o PermissionsChange PermissionsChange.c


clean:
	$(RM) PermissionsCheck
	$(RM) PermissionsChange