all: mcgls-pkg

mcgls-pkg: mcgls
	sudo dpkg-deb --build mcgls

clean: 
	@-rm -vf *.deb
