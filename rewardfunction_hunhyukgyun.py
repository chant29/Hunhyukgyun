def reward_function(params):
   
    all_wheels_on_track = params['all_wheels_on_track']
    distance_from_center = params['distance_from_center']
    track_width = params['track_width']
    objects_distance = params['objects_distance']
    _, next_object_index = params['closest_objects']
    is_crashed = params['is_crashed']
    is_left_of_center = params['is_left_of_center']
    closest_waypoints = params['closest_waypoints']
    
    reward = 1e-3
    reward_lane = 1
    reward_avoid = 1
    
    right_lane = [34, 35, 36]
    

    # Reward if the agent stays inside the two borders of the track
    if (closest_waypoints[1] in right_lane and not is_left_of_center):
        reward_lane = 1.0
    else:
        if distance_from_center < 0.35 * track_width:
            reward_lane = 1.0
        elif distance_from_center < 0.5 * track_width:
            reward_lane = 3.33 - 6.66 * distance_from_center/track_width + 1e-3
        else:
            reward_lane = 1e-3
        
    # Distance to the next object
    distance_closest_object = objects_distance[next_object_index]

    if distance_closest_object < 0.25 * track_width :
        reward_avoid = 1e-3
    elif 0.25 * track_width <= distance_closest_object < 0.6 * track_width:
        reward_avoid = (distance_closest_object - 0.25 * track_width) / (0.35 * track_width) + 1e-3
    else:
        reward_avoid = 1.0

    # Calculate reward by putting different weights on
    # the two aspects above
    reward = 1.0 * reward_lane + 2.0 * reward_avoid

    if is_crashed or not all_wheels_on_track:
         reward = 1e-3

    return reward
