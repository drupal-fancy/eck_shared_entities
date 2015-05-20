<?php
$plugin = array(
  'label' => 'Shared Entity Title (required for the shared flag)',
  'default_widget' => 'eck_shared_entities_shared_entity_title_property_widget'
);

function eck_shared_entities_shared_entity_title_property_widget($property, $vars) {
  $entity = $vars['entity'];
  list($id) = entity_extract_ids($entity->entityType(), $entity);

  $shared_entity_title_widget = array(
    '#type' => 'textfield',
    '#title' => t('Shared entity title'),
    '#default_value' => $entity->{$property},
    '#description' => t('Enter a descriptive title for this entity so that other users can find it.'),
    '#weight' => 91,
    '#hidden' => TRUE,
    '#states' => array(
      'visible' => array(
        '[data-shared-entity-flag-' . $entity->entityType() . '="' . $id . '"]:input' => array('checked' => TRUE),
      )
    )
  );

  return $shared_entity_title_widget;
}