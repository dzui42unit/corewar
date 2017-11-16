# corewar
Create a virtual arena where programs written in a simple language fight one another. Explore the design of a VM (with the relevant instructions, records, etc.) and challenges related to compiling an assembly language in byte-code. As a bonus, you'll be able to enjoy programming your heroes to win the arena battles. Let the building begin and let the best hero win!

Corewar is a very peculiar game. It’s about bringing “players” together around a
“virtual machine”, which will load some “champions” who will fight against one another
with the support of “processes”, with the objective being for these champions
to stay “alive”.

• The processes are executed sequentially within the same virtual machine and memory
space. They can therefore, among other things, write and rewrite on top of
each others so to corrupt one another, force the others to execute instructions that
can damage them, try to rewrite on the go the coding equivalent of a Côtes du
Rhône 1982 (that is one delicious French wine!), etc...
• The game ends when all the processes are dead. The winner is the last player
reported to be “alive”

This project can be broken down into three distinctive parts:
• The assembler: this is the program that will compile your champions and translate
them from the language you will write them in (assembly language) into “Bytecode”.Bytecode
is a machine code, which will be directly interpreted by the virtual
machine.
• The virtual machine: It’s the “arena” in which your champions will be executed.
It offers various functions, all of which will be useful for the battle of the champions.
Obviously, the virtual machine should allow for numerous simultaneous processes;
we are asking you for a gladiator fight, not a one-man show simulator.
• The champion: This one is a special case. Later, in the championship, you will
need to render a super powerful champion, who will scare the staff team to death.
However, rendering this kind of champion is serious work. And since, for now, we
are mostly interested in your capacity to create Corewar’s other programs (i.e. the
assembler and virtual machine), your current champion will only need to prove to
us that you can write bits and pieces of Corewar ASM. This means that the champion
you should render for this project only needs to scare the bejesus out of a
neurasthenic hedgehog.

# The virtual machine
• Each process will have available the following exclusive elements available:
• REG_NUMBER registries, each of which are the size REG_SIZE octets. A
registry is a small memory “box” with only one value. On a real machine, it
is an internal of the processor and as a result very FAST to access.
• A PC ("Program Counter"). This is a special registry that only contains, within
the memory of the virtual machine, the address of the next set of instructions
to code and execute. Very useful to figure out where we are at in the execution,
giving us tips on when to write stuff in the memory...
• A flag named carry, if the latest operation was successful. Only certain operations
can modify the carry.
• The number of the player is generated by the machine or specified at launch and is
given to the champions via the r1 registry of their first process at startup. All the
other registries are at 0, except PC.
• The champions are charged within the memory so that they can space out evenly
their entry points.
• The virtual machine will create a memory space dedicated to the combat of the
players, it will then load each champion and their associated processes and execute
them sequentially until they die.
• Every CYCLE_TO_DIE cycles, the machine needs to make sure that each process
has executed at least one live since the last check. A process that does not abide
by this rule will be killed immediately with a virtual foamy bat (bonus for sound
effect!)
• If during one of those checkup we notice that there has been at least one NBR_LIVE
execution of live since the latest check up, we will decrease CYCLE_TO_DIE of
CYCLE_DELTA units.
• The game is over when all processes are dead
• The winner is the last player to be reported alive. The machine will then show
“Player X (champion_name) won”, where X is the player’s number and champion_name
is its name.
For example: “Player 2 (rainbowdash) won”.
• For each valid execution of the live instruction, the machine must display:
“A process shows that player X (champion_name) is alive”.
• In any case, memory is circular and of MEM_SIZE octets.
• In case of an error, you must display a relevant error message on the standard error
output.
• If CYCLE_TO_DIE wasn’t decreased since MAX_CHECKS checkups, decrease
it.
• The virtual machine should be executed in such a way: ./corewar > ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...
• -dump nbr_cycles
at the end of nbr_cycles of executions, dump the memory on the standard output
and quit the game. The memory must be dumped in the hexadecimal format with
32 octets per line.
• -n number
sets the number of the next player. If non-existent, the player will have the next
available number in the order of the parameters. The last player will have the first
process in the order of execution.
• The champions cannot go over CHAMP_MAX_SIZE, otherwise it is an error.

# Assembler
• Your virtual machine will execute a machine code (or “bytecode”) that will be
generated by your assembler. The assembler (the program) will get a file written in
assembly language as argument and generate a champion that will be understood
by the virtual machine.
• It will run like that:
> ./asm mychampion.s
• It will read the assembly’s code processed from the file .s given as argument, and
write the resulting bytecode in a file named same as the argument by replacing the
extension .s by .cor.
• In case of an error, you will need to display a relevant message on the standard
error output and not create the .cor file.

# The champion
• Your champion are three intrinsic objectives: Make sure its player is reported
“alive”, understand the meaning of life, and eradicate its opponents.
• For your player to be qualified as “alive”, your champion must make sure that some
live are achieved with its number. If one of the processes does a live with the
number of another player... well tough luck, but at least another player will be
happy. If the process of another player scores a live with your number, you are
authorized to make fun of him and you can cash in on his mistake, while insulting
his family in binary code.
• All, and absolutely ALL the instructions are useful. All the machine’s reactions,
described further in the chapter on language can be used to give life to your champion
and enable him to win a prize of seventeen euros and fifty three cents in the
championship. Yes, even the aff instruction is useful to laugh at the uselessness of
your opponents.
• Your champion will be graded during defence on its capacity to survive a few basic
challenges, such as defeating a champion with the IQ of a banana, managing to eat
my grand mother’s apple pie, or drawing flowers in a cappuccino.
• Later, you will get the chance to create a new champion, who will be destined to
fight in a championship (remember: that’s another project!) and fight against your
classmates’ champions, maybe even against one of the staff’s champions, which
might quickly transform your own champion into a pile of virtual casings. Yet it’s
highly possible that after a bit of voodoo, including some dark magic, a safety
pin and a particular place that moral and decency forbids me to name, you might
end up covered in glory and kittens.