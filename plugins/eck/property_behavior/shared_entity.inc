<?php
$plugin = array(
  'label' => 'Shared Entity Flag',
  'default_widget' => 'eck_shared_entities_shared_entity_property_widget'
);

function eck_shared_entities_shared_entity_property_widget($property, $vars) {
  $entity = $vars['entity'];

  $shared_entity_widget = array(
    '#type' => 'checkbox',
    '#title' => t('Share entity'),
    '#default_value' => $entity->{$property},
    '#description' => t('Share this @label entity to make it available for reuse.', array('@label' => $entity->type)),
    '#weight' => 90
  );

  return $shared_entity_widget;
}