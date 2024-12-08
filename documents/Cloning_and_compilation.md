# Cloning the repository and compiling it

To clone the repository, it is recomended to use either the https option or the ssh option (if you have an ssh key associated with your account). For this example, the https option will be used. Now, type into your terminal the following command.

```terminal
git clone https://github.com/ECCIUCRLQ/proyecto-chikistrikis.git
```

Now, that the repository is cloned, it is time to set up the project using your Simics installation. The following steps depend on where you installed Simics and where you cloned the repository. Follow the next instructions to set up your project.

```terminal
cd ../proyecto-chikistrikis/src/
../../installation/simics-6.0.XXX/bin/project-setup --ignore-existing-files
```

Now that Simics has set up the necessary tools to run the project, type the following commands.

```terminal
make
./simics ./targets/qsp-x86/custom-target.simics
run
```

Note: type "run" on the simics terminal (simics>).

The project is now running and the PCI device has been connected to the motherboard via the simulation.

[Return to README](../README.md)
