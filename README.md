# Agents2Tasks

Allocate agents to tasks in multiple timeslots containing multiple tasks.

# Usage

`>Agents2Tasks (specification filepath ) ( output filepath )`

[File format documentation](https://github.com/JamesBremner/Agents2Tasks/wiki/File-format)

# Constraints

- Assigning an agent blocks the agent from being assigned again in the same timeslot, or in later timeslots for a period of time
- The cheapest agent is assigned first
- Agents with smaller assignment counts to previous timeslots will be assigned first
- Assigning an agent to a timeslot causes other agents in the same family to be assigned to the same timeslot if possible and everything else being equal
- Agents can be assigned to groups that are assigned all together or not at all.


# Algorithm

- Loop over timeslots
   - Loop over tasks in timeslot
       - Loop over tasks
            - Set picked agent to null
            - Loop over agents in preferred order of assignment
                 - IF agent can be assigned, is cheaper and has lower previous workload than picked
                     - Set picked agent to current
           - Assign picked agent to task





