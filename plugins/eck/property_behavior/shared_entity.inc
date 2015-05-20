<?php
$plugin = array(
  'label' => 'Shared Entity Flag',
  'default_widget' => 'eck_shared_entities_shared_entity_property_widget'
);

function eck_shared_entities_shared_entity_property_widget($property, $vars) {
  $entity = $vars['entity'];
  list($id) = entity_extract_ids($entity->entityType(), $entity);

  $shared_entity_widget = array(
    '#type' => 'checkbox',
    '#title' => t('Share entity'),
    '#default_value' => $entity->{$property},
    '#description' => t('Share this @label entity to make it available for reuse.', array('@label' => $entity->type)),
    '#attributes' => array('data-shared-entity-flag-' . $entity->entityType() => $id),
    '#weight' => 90
  );

  return $shared_entity_widget;
}